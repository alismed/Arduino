require 'artoo'

connection :arduino, adaptor: :firmata, port: '/dev/ttyACM0'
device :led, driver: :led, pin: 8

work do
  every 1.second do
    led.on? ? led.off : led.on
  end
end
