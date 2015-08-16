require 'artoo'

connection :arduino, adaptor: :firmata, port: '/dev/tty.usbmodem1411'

device :led, driver: :led, pin: 13
device :board, :driver => :device_info

work do
  puts "Firmware name: #{board.firmware_name}"
  puts "Firmata version: #{board.version}"
  
  every 1.second do
  	puts "here"
  end
end