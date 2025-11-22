# Find Rects Example
#
# This example shows off how to find rectangles in the image using the quad threshold
# detection code from our April Tags code. The quad threshold detection algorithm
# detects rectangles in an extremely robust way and is much better than Hough
# Transform based methods. For example, it can still detect rectangles even when lens
# distortion causes those rectangles to look bent. Rounded rectangles are no problem!
# (But, given this the code will also detect small radius circles too)...

#x,y互换了位置使用屏幕时
#使用 cv_lite.rgb888_find_rectangles_with_corners（8.2）(cx=243,cy=158)
import time, os, gc, sys,math
from math import atan,sqrt,atan2,sqrt
from media.sensor import *
from media.display import *
from media.media import *
import cv_lite
from time import ticks_ms
from machine import UART
from machine import FPIOA
from machine import Pin

# 实例化FPIOA
fpioa = FPIOA()
# 设置PIN60为PWM通道0
fpioa.set_function(11, fpioa.UART2_TXD)
fpioa.set_function(12, fpioa.UART2_RXD)
fpioa.set_function(32, FPIOA.GPIO32)
fpioa.set_function(33, FPIOA.GPIO33)

INC_KEY = Pin(32, Pin.IN, Pin.PULL_UP)   # 增大
DEC_KEY = Pin(33, Pin.IN, Pin.PULL_UP)    # 减小

# UART2: baudrate 115200, 8bits, parity none, one stopbits
uart = UART(UART.UART2, baudrate=115200, bits=UART.EIGHTBITS, parity=UART.PARITY_NONE, stop=UART.STOPBITS_ONE)

DETECT_WIDTH = ALIGN_UP(800, 16)
DETECT_HEIGHT = 480
lst=[[1,2],[1,2],[1,2],[1,2]]
sensor = None
#image_shape = [480,800]  # 高，宽
image_shape = [320,480]  # 高，宽
# -------------------------------
# 可调参数（建议调试时调整）/ Adjustable parameters (recommended for tuning)
# -------------------------------
canny_thresh1       = 50        # Canny 边缘检测低阈值 / Canny edge low threshold
canny_thresh2       = 150       # Canny 边缘检测高阈值 / Canny edge high threshold
approx_epsilon      = 0.04      # 多边形拟合精度（比例） / Polygon approximation precision (ratio)
area_min_ratio      = 0.001     # 最小面积比例（0~1） / Minimum area ratio (0~1)
max_angle_cos       = 0.5       # 最大角余弦（值越小越接近矩形） / Max cosine of angle (smaller closer to rectangle)
gaussian_blur_size  = 5         # 高斯模糊核大小（奇数） / Gaussian blur kernel size (odd number)
length_threshold=120
last=0



def format_coord(coord):
    # 格式化为：符号位（+/-） + 3 位数值（补零）
    return f"{coord:+04d}"  # 如 -123 → "-123"，12 → "+012"
def split_to_2d(arr, cols=1):
    return [arr[i:i + cols] for i in range(0, len(arr), cols)]
def get_vertices(rect):
    x, y, w, h = rect
    # 计算四个顶点坐标
    top_left = (x, y)
    top_right = (x + w, y)
    bottom_right = (x + w, y + h)
    bottom_left = (x, y + h)
    return [top_left, top_right, bottom_right, bottom_left]
def find_max(arr):
    max_size=0
    for s in range (len(arr)):
        if arr[s][2]*arr[s][3] > max_size:
            max_blob=arr[s]
            max_size = arr[s][2]*arr[s][3]
    return max_blob

 # 定义一个函数来判断两条线段是否平行
def are_segments_parallel(theta1, theta2, tolerance=30):
    # 计算角度差
    angle_difference = abs(theta1 - theta2)
    if(angle_difference>180):angle_difference=angle_difference-180
    # 检查角度差是否为0度或180度（考虑浮点数精度）
    return math.isclose(angle_difference, 0, abs_tol=tolerance) or math.isclose(angle_difference, 180, abs_tol=tolerance)
def are_segments_vertical(theta1, theta2, tolerance=30):
    # 计算角度差
    angle_difference = abs(theta1 - theta2)
    if(angle_difference>180):angle_difference=angle_difference-180
    # 检查角度差是否为0度或180度（考虑浮点数精度）
    return math.isclose(angle_difference, 90, abs_tol=tolerance)
def find_intersection(x1, y1, x2, y2, x3, y3, x4, y4):
    def calculate_determinant(A, B):
        return A[0] * B[1] - A[1] * B[0]

    # 向量 AB 和 AC
    AB = (x2 - x1, y2 - y1)
    AC = (x3 - x1, y3 - y1)
    # 向量 CD
    CD = (x4 - x3, y4 - y3)

    # 计算叉积 determinant(AB, CD)
    det = calculate_determinant(AB, CD)

    if det == 0:
        # 直线平行或共线，没有唯一交点
        return None

    # 向量 DA
    DA = (x1 - x4, y1 - y4)

    # 计算参数 t 和 u
    t = calculate_determinant(AC, CD) / det
    u = calculate_determinant(AC, AB) / det

    # 计算交点坐标
    intersection_x = x1 + t * AB[0]
    intersection_y = y1 + t * AB[1]

    return int(intersection_x), int(intersection_y)
#def are_segments_vertical(len1, len2, tolerance=0.2):
#        # 计算角度差
#        len_bili = 1en1/1en2
#        if(angle_difference>180):angle_difference=angle_difference-180
#        # 检查角度差是否为0度或180度（考虑浮点数精度）
#        return math.isclose(angle_difference, 90, abs_tol=tolerance)
def camera_init():
    global sensor

    # construct a Sensor object with default configure
    sensor = Sensor()
    # sensor reset
    sensor.reset()
    # set hmirror
    # sensor.set_hmirror(False)
    # sensor vflip
    # sensor.set_vflip(False)

    # set chn0 output size
#    sensor.set_framesize(width=DETECT_WIDTH,height=DETECT_HEIGHT)
    sensor.set_framesize(width=480, height=320)
    # set chn0 output format
    sensor.set_pixformat(Sensor.RGB888)

    # use IDE as display output
    #使用时x，y坐标在UI上发生改变，真实坐标不变
    Display.init(Display.ST7701, width= DETECT_WIDTH, height = DETECT_HEIGHT,fps=100,to_ide = True)

#    Display.init(Display.VIRT, width= DETECT_WIDTH, height = DETECT_HEIGHT,fps=100,to_ide = True)

    # init media manager
    MediaManager.init()
    # sensor start run
    sensor.run()

def camera_deinit():
    global sensor
    # sensor stop run
    sensor.stop()
    # deinit display
    Display.deinit()
    # sleep
    os.exitpoint(os.EXITPOINT_ENABLE_SLEEP)
    time.sleep_ms(100)
    # release media buffer
    MediaManager.deinit()

def capture_picture():#UI显示上x和y对调

    fps = time.clock()
    S_THRESHOLD = 2000  # 默认阈值
    THRESHOLD_MIN = 500  # 最小阈值
    THRESHOLD_MAX = 10000  # 最大阈值
    THRESHOLD_STEP = 500  # 调整步长
    # 按键消抖参数
    last_key_time = 0
    DEBOUNCE_DELAY = 200  # 200ms消抖


    while True:
        fps.tick()
        rect_flag=0
        current_time = ticks_ms()

        try:
            os.exitpoint()
            global sensor
#            global S
            img = sensor.snapshot()
            img_np = img.to_numpy_ref()  # 获取 RGB888 ndarray 引用 / Get RGB888 ndarray reference
            rects = cv_lite.rgb888_find_rectangles_with_corners(
                image_shape, img_np,
                canny_thresh1, canny_thresh2,
                approx_epsilon,
                area_min_ratio,
                max_angle_cos,
                gaussian_blur_size
            )
            # 读取原始按键状态
            inc_key_raw = INC_KEY.value()
            dec_key_raw = DEC_KEY.value()

            # 按键消抖处理
            inc_key_pressed = (inc_key_raw == 0) and (time.ticks_diff(current_time, last_key_time) > DEBOUNCE_DELAY)
            dec_key_pressed = (dec_key_raw == 0) and (time.ticks_diff(current_time, last_key_time) > DEBOUNCE_DELAY)

            # 参数增加逻辑
            if inc_key_pressed:
                S_THRESHOLD = min(THRESHOLD_MAX, S_THRESHOLD + THRESHOLD_STEP)
                last_key_time = current_time
                print(f"阈值增加到: {S_THRESHOLD}")

            # 参数减少逻辑
            if dec_key_pressed:
                S_THRESHOLD = max(THRESHOLD_MIN, S_THRESHOLD - THRESHOLD_STEP)
                last_key_time = current_time
                print(f"阈值减少到: {S_THRESHOLD}")

            print("rects",rects)
            if(rects):
                max_rects = find_max(rects)
                #print("max_rects",max_rects)
                c=[[1,2],[1,2],[1,2],[1,2]]

                for i in range(4):
                    c[i][0] = max_rects[2*i+4]
                    c[i][1] = max_rects[2*i+5]
                for s in range (1,5):
                            if s == 4:
                                s=0
                            img.draw_line(c[s-1][0],c[s-1][1],c[s][0],c[s][1],color=(255, 0, 0),thickness=3)#img.draw_edges(c)等价 画矩形外框
                            img.draw_circle(c[s-1][0],c[s-1][1],2,color=(0, 0, 255),fill=True,thickness=3)
                len1=sqrt(pow(c[0][0]-c[1][0],2)+pow(c[0][1]-c[1][1],2))#0左上
                len2=sqrt(pow(c[2][0]-c[3][0],2)+pow(c[2][1]-c[3][1],2))#1左下
                len3=sqrt(pow(c[0][0]-c[3][0],2)+pow(c[0][1]-c[3][1],2))#2右下
                len4=sqrt(pow(c[1][0]-c[2][0],2)+pow(c[1][1]-c[2][1],2))#3右上

                #print("len1",len1)
                #print("len2",len2)
                #print("len3",len3)
                #print("len4",len4)

                S=max_rects[2]*max_rects[3]
                #print("S",S)

                err1=(abs(len1-len2))#对边差值
                err2=(abs(len3-len4))
#                print("err1",err1)
#                print("err2",err2)
                if(S>S_THRESHOLD and err1<length_threshold and err2<length_threshold and len1>30 and len2>30 and len3>30 and len4>30):
#                    bili=float(len1/len3)
#                    print("bili",bili)
                   # 计算每条线段的 theta):#
                    theta1 = math.atan2(c[0][1]-c[1][1], c[0][0]-c[1][0])
                    theta2 = math.atan2(c[2][1]-c[3][1], c[2][0]-c[3][0])
                    theta3 = math.atan2(c[0][1]-c[3][1], c[0][0]-c[3][0])
                    theta4 = math.atan2(c[1][1]-c[2][1], c[1][0]-c[2][0])

                    # 将弧度转换为角度
                    theta1_degrees = math.degrees(theta1)
                    theta2_degrees = math.degrees(theta2)
                    theta3_degrees = math.degrees(theta3)
                    theta4_degrees = math.degrees(theta4)
#                    print("theta1",theta1_degrees)
#                    print("theta2",theta2_degrees)
#                    print("theta3",theta3_degrees)
#                    print("theta4",theta4_degrees)

                    #线段是否平行和垂直
                    is_line1_line2_parallel = are_segments_parallel(theta1_degrees, theta2_degrees)
                    is_line3_line4_parallel = are_segments_parallel(theta3_degrees, theta4_degrees)
                    is_line1_line3_vertical = are_segments_vertical(theta1_degrees, theta3_degrees)

                    if (is_line1_line3_vertical and is_line1_line2_parallel and is_line3_line4_parallel  ):#标准矩形的条件
                          rect_flag=1
                          for s in range (4):#保存四个顶点
                              lst[s][0]=c[s][0]
                              lst[s][1]=c[s][1]
                    else: rect_flag=0
                else:rect_flag=0
            else:rect_flag=0
            if rect_flag==1:#识别出标准矩形
                intersection = find_intersection(lst[0][0], lst[0][1], lst[2][0], lst[2][1], lst[1][0], lst[1][1], lst[3][0], lst[3][1])
                img.draw_circle(intersection[0], intersection[1], 1, color=(255, 0, 0), thickness=4)
#                global last_dot
#                distance = math.sqrt((intersection[0] - last_dot[0]) ** 2 + (intersection[1] - last_dot[1]) ** 2)
                # 如果距离小于或等于阈值，则发送数据
#                print("(cx=%s,cy=%s)"%(last_dot[0], last_dot[1]))
                print("(cx=%s,cy=%s)"%(intersection[0], intersection[1]))
                img.draw_string_advanced(0,0,30,"(x=%s,y=%s)"%(intersection[0], intersection[1]),color=(255, 255, 0),scale=3)
#                if distance <= 100 or last_dot[0]==0 :#坐标变换合理时
#                    for s in range (1,5):
#                           if s == 4:
#                               s=0
#                           img.draw_line(c[s-1][0],c[s-1][1],c[s][0],c[s][1],color=(0, 255, 0),thickness=3)#img.draw_edges(c)等价 画矩形外框
#                           img.draw_circle(c[s-1][0],c[s-1][1],2,color=(0, 0, 255),fill=True,thickness=3)
#                    uart.write("(x=%s,y=%s)" % (intersection[0], intersection[1]))
#                    img.draw_string_advanced(0,0,50,"(x=%s,y=%s)"%(intersection[0], intersection[1]),color=(255, 255, 0),scale=3)
##                   print("(cx=%s,cy=%s)"%(intersection[0], intersection[1]))
#                    last_dot=intersection
                for s in range (1,5):
                       if s == 4:
                           s=0
                       img.draw_line(c[s-1][0],c[s-1][1],c[s][0],c[s][1],color=(0, 255, 0),thickness=3)#img.draw_edges(c)等价 画矩形外框
                       img.draw_circle(c[s-1][0],c[s-1][1],2,color=(0, 0, 255),fill=True,thickness=3)
                wucha_center = (240-intersection[0], 160-intersection[1])
                wucha_xcenter=240-intersection[0]
                wucha_ycenter=160-intersection[1]
                out_str1 = '['  # 起始校验符
                out_str1 += f'{format_coord(wucha_xcenter)}'      # x
                out_str1 += f'{format_coord(wucha_ycenter)}'      # y
                out_str1 += '*]'  # 终止校验符
                 # 发送数据
                uart.write(out_str1)
                #uart.write("(x=%s,y=%s)" % (intersection[0], intersection[1]))
                img.draw_string_advanced(200,0,30,"fps:%s"%int(fps.fps()),color=(0, 255, 0))
                Display.show_image(img) # Take a picture and display the image.
            else:
                img.draw_string_advanced(20,50,30,"fps:%s"%int(fps.fps()),color=(0, 255, 0))
                img.draw_string_advanced(10, 0, 30, "S_THRESHOLD:{}".format(S_THRESHOLD), color=(255, 0, 0))
                Display.show_image(img)
                uart.write("(x=999,y=999)")
#            print("fps",fps.fps())

        except KeyboardInterrupt as e:
            print("user stop: ", e)
            break
        except BaseException as e:
            print(f"Exception {e}")
            break

def main():
    os.exitpoint(os.EXITPOINT_ENABLE)
    camera_is_init = False
    try:
        print("camera init")
        camera_init()
        camera_is_init = True
        print("camera capture")
        capture_picture()
    except Exception as e:
        print(f"Exception {e}")
    finally:
        if camera_is_init:
            print("camera deinit")
            camera_deinit()

if __name__ == "__main__":
    main()
