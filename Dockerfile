FROM debian:buster

# STM32 flasher
RUN apt update
RUN apt install -y git gcc make
RUN git clone https://git.code.sf.net/p/stm32flash/code /tmp/stm32flash-code
RUN cd /tmp/stm32flash-code && make && make install

# GCC toolchain 
RUN apt install -y gcc-arm-none-eabi

# STM32 CMSIS libraries
ADD STM32Cube_FW_F1_V1.8.0 /tmp/STM32Cube_FW_F1_V1.8.0

# Optional dev stuff
RUN apt install -y vim
