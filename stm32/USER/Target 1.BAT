SET PATH=D:\Keil\ARM\ARMCC\bin\;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;E:\Program Files\MATLAB\R2016a\runtime\win64;E:\Program Files\MATLAB\R2016a\bin;E:\Program Files\MATLAB\R2016a\polyspace\bin;D:\Program Files (x86)\Altium Designer Summer 09\System;C:\Windows\system32\config\systemprofile\.dnx\bin;C:\Program Files\Microsoft DNX\Dnvm\;C:\Program Files (x86)\Windows Kits\8.1\Windows Performance Toolkit\;C:\Program Files\Microsoft SQL Server\130\Tools\Binn\;D:\Program Files\Git\cmd;D:\Program Files\TortoiseGit\bin;C:\Users\hasee\AppData\Local\Programs\Python\Python35\Scripts\;C:\Users\hasee\AppData\Local\Programs\Python\Python35\;C:\Users\hasee\AppData\Local\Microsoft\WindowsApps;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\
SET CPU_TYPE=STM32F103RC
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x007A1200
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\main.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\stm32f10x_it.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\system_stm32f10x.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\led.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\key.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\myiic.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\apds_9960.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\apds_9960_deal.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\delay.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\sys.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\usart.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\core_cm3.__i"
"D:\Keil\ARM\ARMCC\bin\ArmAsm" --Via ".\startup_stm32f10x_hd._ia"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\stm32f10x_gpio.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\stm32f10x_rcc.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\stm32f10x_usart.__i"
"D:\Keil\ARM\ARMCC\bin\ArmCC" --Via ".\misc.__i"
"D:\Keil\ARM\ARMCC\bin\ArmLink" --Via ".\IIC.lnp"
