IMAGE_TAG = stm32_dev
STM32_SERIAL_DEV = /dev/ttyUSB0
PROGRAMS_PATH = /stm32dev
DOCKER_RUN_ARGS = \
 --device=$(STM32_SERIAL_DEV) \
 -e STM32_SERIAL_DEV=$(STM32_SERIAL_DEV) \
 --mount type=bind,source=$(shell pwd)/programs,target=$(PROGRAMS_PATH) \
 -w $(PROGRAMS_PATH)

build:
	docker build -t $(IMAGE_TAG) .

run:
	docker run \
		-it \
		$(DOCKER_RUN_ARGS) \
		$(IMAGE_TAG) \
		/bin/bash

clean:
	docker system prune -f

totalclean: clean
	docker image prune -a -f

test:
	docker run \
		$(DOCKER_RUN_ARGS) \
		$(IMAGE_TAG) \
		sh -c "cd $(PROGRAMS_PATH)/blink; make"
