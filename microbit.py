# Python code
#
b0 = 0
b1 = 0
sck = 0
ligth_value = 0

def on_forever():
  global ligth_value
  pins.digital_write_pin(DigitalPin.P15, 1)
  ligth_value = input.light_level()
  if ligth_value < 63:
    pins.digital_write_pin(DigitalPin.P13, 0)
    pins.digital_write_pin(DigitalPin.P14, 0)
  else:
    if ligth_value < 126:
      pins.digital_write_pin(DigitalPin.P13, 1)
      pins.digital_write_pin(DigitalPin.P14, 0)
    else:
      if ligth_value < 189:
        pins.digital_write_pin(DigitalPin.P13, 0)
        pins.digital_write_pin(DigitalPin.P14, 1)
      else:
        pins.digital_write_pin(DigitalPin.P13, 1)
        pins.digital_write_pin(DigitalPin.P14, 1)
  pins.digital_write_pin(DigitalPin.P15, 0)
  basic.pause(100)
basic.forever(on_forever)

