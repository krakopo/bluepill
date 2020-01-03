IMAGE_TAG = stm32_dev
STM32_SERIAL_DEV = /dev/ttyUSB0

build:
	docker build -t $(IMAGE_TAG) .

run:
	docker run -it --device=$(STM32_SERIAL_DEV) -e STM32_SERIAL_DEV=$(STM32_SERIAL_DEV) $(IMAGE_TAG) /bin/bash

clean:
	docker system prune -f

totalclean: clean
	docker image prune -a -f

test:
	docker run --device=$(STM32_SERIAL_DEV) -e STM32_SERIAL_DEV=$(STM32_SERIAL_DEV) $(IMAGE_TAG) sh -c "cd /tmp/samples; make"
