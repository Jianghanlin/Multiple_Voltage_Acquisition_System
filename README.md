# 【51单片机】基于STC89C52RC的多路电压采集系统

![渲染图.png](https://cdn.nlark.com/yuque/0/2021/png/1593351/1610973853371-e082bd2b-d955-41a3-99e6-f91bf7f62c3b.png#align=left&display=inline&height=1080&margin=%5Bobject%20Object%5D&name=%E6%B8%B2%E6%9F%93%E5%9B%BE.png&originHeight=1080&originWidth=1920&size=1649986&status=done&style=none&width=1920)<br />随着经济的飞速发展和科学技术水平的不断提高，智能数据采集系统在工业生产以及科学研究中得到了广泛的应用。在信息化时代，数据和信息无疑成为一种重要的资源，而数据采集系统的出现更是进一步促进了人机交互、对设备的自动检测控制等的实现，为现代化工业生产提供了方便。本次课程设计将阐述基于单片机的智能数据采集系统的设计要点及其具体方法，希望对基于单片机的智能数据采集系统的改造和创新做出应有的贡献。<br />此次课程设计利用型号为STC89C52RC的单片机，ADC0809，LCD1602，74HC138等电子元器件。<br />

<a name="cq4TK"></a>
## **多路数据采集控制系统-硬件部分**
**目录**

- **设计题目**
- **设计目的**
- **设计内容及要求**
- **设计过程**
- **总体设计**
> 系统框图关键元件选取

- **PCB设计，基于Altium Designer 20**
- **制作与实现**
> 原理图设计PCB绘制

- **调试及结果**
> Hex文件烧录过程测试数据

- **遇到的问题**
- **心得体会**

---

<a name="SXMyg"></a>
### 1 设计题目

- 单片机多路数据采集控制系统—实物制作
<a name="sacu3"></a>
### 2 设计目的

- 运用单片机原理及其应用等课程知识,根据题目要求进行软硬件系统的设计和调试，从而加深对本课程知识的理解，把学过的比较零碎的知识系统化，比较系统的学习开发单片机应用系统的基本步骤和基本方法，使学生应用知识能力、设计能力、调试能力以及报告撰写能力等有一定的提高
<a name="sNZQB"></a>
### 3 设计内容及要求

- 用8051单片机设计数据采集控制系统，基本要求如下：
> 1、可实现8路数据的采集，假设８路信号均为0-5V的电压信号2、采集数据可通过LCD显示，显示格式为：[通道号] 电压值，如[０１]：４.5V3、可通过键盘设置采集方式（单点采集、多路巡测、采集时间间隔*）4、具有异常数据声音报警功能：对第一路数据可设置正常数据的上限值和下限值，当采集的数据出现异常，发出报警信号

- 根据本人的设计，在原来基本要求的基础上，增加以下新增功能：
> 1、8路通道都可以单独设置上下限电压值并且可以人为通过按键调节并显示在LCD1602上，随时唤醒且自动保存数值2、通道电压不符合上下限值时，蜂鸣器打鸣，同时会有对应通道LED报警3、增加电源上电指示LED4、防止烧坏芯片，增加电源正负极插反指示LED
<a name="JYdMQ"></a>
### 4 总体设计

- 系统框图
> 此次多路数据采集控制系统包括：控制模块，电压采样模块，显示模块，按键模块，时钟模块，报警模块。 控制模块为单片机为STC89C52RC。电压采样模块为8位的AD转换芯片0809。显示模块为LCD1602A液晶显示屏。按键模块有按键、上拉电阻、LED构成。时钟模块为外接12MHz晶振。报警模块有声音报警模块和LED报警模块，声音报警模块由蜂鸣器和三极管构成；LED报警模块由74HC138和LED构成。另外还有其他滤波电容、电阻、LED等元件。其电路总设计框图如下：
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963874-8add2b7a-080c-4b28-ac05-c957571f9131.jpeg#align=left&display=inline&height=514&margin=%5Bobject%20Object%5D&originHeight=617&originWidth=720&size=0&status=done&style=none&width=600)<br />系统框图

- 关键元件选取
> **STC89C52RC**> STC89C52RC是STC公司生产的一种低功耗、高性能CMOS8位微控制器，具有8K字节系统可编程Flash存储器。STC89C52使用经典的MCS-51内核，但是做了很多的改进使得芯片具有传统的51单片机不具备的功能。在单芯片上，拥有灵巧的8 位CPU 和在系统可编程Flash，使得STC89C52为众多嵌入式控制应用系统提供高灵活、超有效的解决方案。32 位I/O 口线，看门狗定时器，内置4KB EEPROM，MAX810复位电路，3个16 位定时器/计数器，4个外部中断，一个7向量4级中断结构（兼容传统51的5向量2级中断结构），全双工串行口。另外STC89C52 可降至0Hz 静态逻辑操作，支持2种软件可选择节电模式。空闲模式下，CPU 停止工作，允许RAM、定时器/计数器、串口、中断继续工作1、数据存储器（RAM）：片内为128B（52子系列为256B），片外最多可扩64KB。片内128B的RAM以高速RAM的形式集成，可加快单片机运行的速度和降低功耗 2、程序存储器（Flash ROM）：片内集成有8KB的Flash存储器，如片内容量不够，片外可外扩至64KB3、中断系统：具有6个中断源，2级中断优先权4、定时器/计数器：2个16位定时器/计数器（52子系列有3个），4种工作方式5、看门狗定时器WDT：当CPU由于干扰使程序陷入死循环或跑飞时，WDT可使程序恢复正常运行关键引脚RESET：复位信号输入，在引脚加上持续时间大于2个机器周期的高电平，可使单片机复位。正常工作，此脚电平应 ≤ 0.5V。当看门狗定时器溢出输出时，该脚将输出长达96个时钟振荡周期的高电平(EA) ̅：1，读取内部存储器。0，读取外部存储器ALE：为CPU访问外部程序存储器或外部数据存储器提供地址锁存信号，将低8位地址锁存在片外的地址锁存器中
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963902-0b210ad7-175f-4df0-9500-9276f2f6c197.jpeg#align=left&display=inline&height=284&margin=%5Bobject%20Object%5D&originHeight=284&originWidth=247&size=0&status=done&style=none&width=247)<br />STC89C52引脚图<br />![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610973963870-df0d8ede-4eab-4b38-8ed7-3e8c81a0844a.jpg#align=left&display=inline&height=172&margin=%5Bobject%20Object%5D&originHeight=172&originWidth=269&size=0&status=done&style=none&width=269)<br />STC89C52实物图<br />![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610973963891-0312ed36-ded5-43cb-b859-8e89d420974d.jpg#align=left&display=inline&height=318&margin=%5Bobject%20Object%5D&originHeight=318&originWidth=554&size=0&status=done&style=none&width=554)<br />STC89C52内部结构
> **ADC0809**> ADC0809是采用COMS工艺制造的双列直插式单片8位A/D转换器。分辨率8位，精度7位，带8个模拟量输入通道，有通道地址译码锁存器，输出带三态数据锁存器。启动信号为脉冲启动方式，最大可调节误差为±1LSB。ADC0809内部没有时钟电路，故CLK时钟需由外部输入，fclk允许范围为500kHz-1MHz，典型值为640kHz。每通道的转换需要66~73个时钟脉冲，大约100-110us。（转换时间）工作温度范围为-40℃—+85℃。功耗为15mW，输入电压范围为0–5V，单一+5V电源供电。 IN0~IN7：8路模拟信号输入端 D0~D7：8位数字量输出端 START：启动控制输入端，高电平有效，用于启动ADC0809内部的A/D转换过程 ALE：地址锁存控制输入端，ALE端可与START端连接在一起，通过软件输入一个正脉冲，可立即启动A/D转换 EOC：转换结束信号输出端，开始A/D转换时为低电平，转换结束是输出高电平 OE：输出允许控制端，用于打开三态输出锁存器，当OE为高电平时，打开三态数据输出锁存器，将转换后的数据凉输送到数据总线上 CLK：始终信号输入端 ADDA(ADDB、ADDC)：8路模拟选通开关的3位地址选通输入端
![](https://cdn.nlark.com/yuque/0/2021/png/1593351/1610973963912-b156e2dd-76de-4517-9b70-a9888609e0cb.png#align=left&display=inline&height=206&margin=%5Bobject%20Object%5D&originHeight=206&originWidth=176&size=0&status=done&style=none&width=176)<br />ADC0809引脚<br />![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610973963854-a780f81d-56a0-44ee-87d4-924b37658775.jpg#align=left&display=inline&height=147&margin=%5Bobject%20Object%5D&originHeight=147&originWidth=242&size=0&status=done&style=none&width=242)<br />ADC0809实物图
> **LCD1602**> LCD1602液晶显示器是广泛使用的一种字符型液晶显示模块。它是由字符型液晶显示屏（LCD）、控制驱动主电路HD44780及其扩展驱动电路HD44100，以及少量电阻、电容元件和结构件等装配在PCB板上而组成 Pin1：VSS为地电源 Pin2：VDD接5V正电源 Pin3：VL为液晶显示器对比度调整端，接正电源时对比度最弱，接地时对比度最高，对比度过高时会产生“鬼影”现象，使用时可以通过一个10kQ的电位器调整其对比度 Pin4：RS为寄存器选择脚，高电平时选择数据寄存器、低电平时选择指令寄存器 Pin5：R/W为读/写信号线，高电平时进行读操作，低电平时进行写操作。当RS和R/W共同为低电平时可以写入指令或显示地址；当RS为低电平，R/W为高电平时，可以读忙信号；当RS为高电平，R/W为低电平时，可以写入数据 Pin6：E端为使能端，当E端由高电平跳变为低电平时，液晶模块执行命令 Pin7 ~ 14：D0~D7为8位双向数据线 Pin15：背光源正极 Pin16：背光源负极
![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610973963881-15b00041-1375-4b00-a429-e0a5c6408ec4.jpg#align=left&display=inline&height=117&margin=%5Bobject%20Object%5D&originHeight=117&originWidth=285&size=0&status=done&style=none&width=285)<br />LCD俯视图<br />![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963911-00e6e3c6-d139-4b8b-ac17-450b09b27de7.jpeg#align=left&display=inline&height=115&margin=%5Bobject%20Object%5D&originHeight=115&originWidth=248&size=0&status=done&style=none&width=248)<br />背部视图<br />![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963899-fa3d78c3-4335-40e6-9ea7-c1ac8dee3839.jpeg#align=left&display=inline&height=107&margin=%5Bobject%20Object%5D&originHeight=107&originWidth=237&size=0&status=done&style=none&width=237)<br />LCD实物图<br />![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963877-2a39dc73-3d48-4100-be31-60f8bf298415.jpeg#align=left&display=inline&height=107&margin=%5Bobject%20Object%5D&originHeight=107&originWidth=212&size=0&status=done&style=none&width=212)<br />对应引脚
> **74HC138**> 74HC238能够将3地址输入，译码出8个输出。用3个IO，可以控制8个输出。A0~A2：3个输入。E1反、E2反：拉低使能，可以接地。E3：拉高使能，可以接VCC。Y0反到Y7反：8个输出。
![](https://cdn.nlark.com/yuque/0/2021/png/1593351/1610973963912-f590f04b-0005-4fc7-9471-05cd30667f4a.png#align=left&display=inline&height=161&margin=%5Bobject%20Object%5D&originHeight=161&originWidth=187&size=0&status=done&style=none&width=187)<br />引脚图<br />![](https://cdn.nlark.com/yuque/0/2021/png/1593351/1610973963936-a56e873f-de49-4046-93cc-c8e31dc71cb4.png#align=left&display=inline&height=162&margin=%5Bobject%20Object%5D&originHeight=162&originWidth=195&size=0&status=done&style=none&width=195)<br />实物图<br />![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610973963891-9e2f770a-7a41-45f4-beed-49db17ae83a4.jpg#align=left&display=inline&height=235&margin=%5Bobject%20Object%5D&originHeight=235&originWidth=374&size=0&status=done&style=none&width=374)<br />74HC138真值表
<a name="UT6Gb"></a>
### 5 PCB设计，基于Altium Designer 20
步骤一：打开软件，新建原理图，新建PCB图。<br />步骤二：从库中寻找元器件绘制电路，并选择封装。<br />步骤三：进行原理图进行电气规则检查，检查无误后待定。<br />步骤四：进入PCB图在Keep Out Layer绘制PCB框的大小为80mm*120mm。<br />步骤五：导出原理图至PCB，规定布线规则后，开始布局和布线。<br />注意点个人陈述：<br />1、 考虑到电源的波动，在靠近所有芯片的供电引脚处都加有10nF的滤波电容，保持供电稳定，消除高频干扰。<br />2、 ADC0809的采样模拟电压来源为电阻分压电路。<br />3、 STC89C52RC的P0口没有上拉电阻需要人为添加排阻进行上拉。
> **控制及LCD显示模块**> 晶振与单片机的脚XTAL0和脚XTAL1构成的振荡电路中会产生谐波（也就是不希望存在的其他频率的波）这个波对电路的影响不大，但会降低电路的时钟振荡器的稳定性。 为了电路的稳定性起见 ATMEL公司只是建议在晶振的两引脚处接入两个10pf-50pf的瓷片电容接地来削减谐波对电路的稳定性的影响，所以晶振所配的电容在10pf-50pf之间都可以的 如上图所示LCD的VL引脚上的电压由滑动变阻器分压得到，用于调节LCD的对比度。BLA为外接电源的正极，BLK为外接电源的负极，用于LCD的背光。STC89C52RC的P2口驱动D0~D1，另外的3个IO，P3.5、P3.6、P3.7分别控制EN、RW、RS
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963936-81675c15-90a3-44e5-b66b-b87c62fe07d0.jpeg#align=left&display=inline&height=453&margin=%5Bobject%20Object%5D&originHeight=652&originWidth=720&size=0&status=done&style=none&width=500)
> **电压采样模块**> 如上图，ADC0809的3地址输入引脚CBA、ALE、EOC、START、OE由STC89C52RC上的IO引脚来控制。8位OUT输出直接由TC89C52RC的P1口来接收。ADC0809的8通道模拟信号输入由外部的电阻分压得到。另外需注意ADC0809芯片工作需要时钟脉冲，所以10引脚的clk由STC89C52RC的30引脚ALE进行供给，因为STC89C52RC正常工作时ALE引脚输出1/6的外接晶振的频率 假设下方滑动变阻器为2.5K为例，IN7的电压接地为0V，其他根据5V分压可以得到： IN0：5V IN1：4.23V IN2：3.4V IN3：2.70V IN4：1.93V IN5：1.17V IN6：0.4V
![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610973963873-e16a0582-9269-4458-8ab4-bd5d47914fef.jpg#align=left&display=inline&height=395&margin=%5Bobject%20Object%5D&originHeight=395&originWidth=359&size=0&status=done&style=none&width=359)
> **按键模块**> 按键模块如下图所示，分为前一通道、后一通道、调节上限、调解下限，还有复位按键。上拉电阻在上电时默认将按键右端置为高电平。一旦按键按下，电阻下方为低电平并传给STC89C52RC对应按键引脚，执行对应操作，并且会有对应LED亮起 复位电路工作原理是VCC上电时，使极性电容C充电，在200欧电阻上出现高电位电压，使得单片机复位；几个毫秒后，C充满，200欧电阻上电流降为0，电压也为0，使得单片机进入工作状态。工作期间，按下S1，C放电，放电结束后，又充电，在200电阻上出现高电压，使得单片机进入复位状态，直到S1松手，C又充电完毕，随后，单片机进入工作状态
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963876-32d28e62-e049-4dcc-a8b1-a49bad8a7298.jpeg#align=left&display=inline&height=243&margin=%5Bobject%20Object%5D&originHeight=243&originWidth=240&size=0&status=done&style=none&width=240)<br />![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610973963931-e32b6a0c-a805-4b32-8dfd-ee56e06a29b5.jpg#align=left&display=inline&height=279&margin=%5Bobject%20Object%5D&originHeight=279&originWidth=302&size=0&status=done&style=none&width=302)
> **报警模块**> 如上图所示，74HC138的CBA由ADC0809的CBA传输共享而来，高电平有效使能端E3交由STC89C52RC的32引脚控制，其他2个低电平有效使能端E1反 、E2反 默认接地。一旦切换到对应通道，如果该通道的电压异常（即采样电压值不在设置的上下限电压区间范围内），那么点亮该通道的LED，进行报警，同时蜂鸣器进行打鸣报警
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963927-34b5d523-4f5c-4089-91df-04855db98132.jpeg#align=left&display=inline&height=194&margin=%5Bobject%20Object%5D&originHeight=194&originWidth=272&size=0&status=done&style=none&width=272)<br />![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963913-79e80089-4415-4281-8a7c-b618e8f032ff.jpeg#align=left&display=inline&height=263&margin=%5Bobject%20Object%5D&originHeight=263&originWidth=527&size=0&status=done&style=none&width=527)
<a name="mn1Of"></a>
### 6 调试及结果

- Hex文件烧录过程
> 首先在Keil uVersion5中定义程序输出路径，进行编译，确保编译成功，如下图所示
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963918-b63e283a-c763-4853-b0e2-0d719893794f.jpeg#align=left&display=inline&height=103&margin=%5Bobject%20Object%5D&originHeight=103&originWidth=379&size=0&status=done&style=none&width=379)
> 接下来打开STC官方烧录软件，插上51开发板，窗口默认检测串口，波特率设置为9600~19200，选择hex文件所在的目录，点击下载，开发板上电，等待程序烧录完成即可
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963949-1334a534-4087-4c68-8e38-f23304851a29.jpeg#align=left&display=inline&height=282&margin=%5Bobject%20Object%5D&originHeight=523&originWidth=720&size=0&status=done&style=none&width=388)

- 测试数据

![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963910-38d55303-7036-4917-95b7-d32806eb03ad.jpeg#align=left&display=inline&height=230&margin=%5Bobject%20Object%5D&originHeight=283&originWidth=737&size=0&status=done&style=none&width=600)![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610973963939-1439bce0-cb13-443a-bf8f-eb9abd07de15.jpeg#align=left&display=inline&height=239&margin=%5Bobject%20Object%5D&originHeight=297&originWidth=720&size=0&status=done&style=none&width=579)
> 实验测量数据如上两表所示，第一次测量数据的电压误差在0.03V上下波动，判断误差来源为3处：外用表、程序算法、硬件电路焊接、电子元件误差。由于万用表，电子元件误差是固定存在的，无法进行认为干预，并且硬件电路焊接也已完成，只能从程序入手，尽可能地使采样值准确。于是，在程序里考虑了多次采样求平均值的算法，编译成功并且烧录后，进行了第二次数据记录，结果取得了良好的效果，可以观察到电压误差在0.02V上下波动
<a name="wHD2d"></a>
### 7 遇到的问题

- LCD1602A显示不正常，乱码
> 根据Proteus的硬件仿真，可以得出不是程序设计的问题，是电路焊接的问题。既然是LCD乱码，就是LCD与STC89C52连接的引脚上出了问题。LCD可以显示内容，对比度工作正常，排除调节对比度的3个引脚。背光电源正常亮起，排除背光电源的2个引脚。剩下11个引脚，经过观察是D0~D7某两个引脚短接，排除短接故障后，上电LCD只能显示半边内容，另外半边乱码。这个情况尝试直接换了一块LCD，显示正常，故障排除

- LCD显示电压有0.03V的误差
> 直接从软件算法入手，采取多次采样求平均值的算法，采样次数为5次，重新测试后，发现有效果，电压误差为0.02V
