$:.unshift File.dirname(__FILE__)

require 'thrift'
require './calculadora.rb'

transport = Thrift::BufferedTransport.new(Thrift::Socket.new('localhost', 9090))
protocol = Thrift::BinaryProtocol.new(transport)
client = Calculadora::Client.new(protocol)

transport.open()

salida = client.suma(1,1)

puts "El resultado de la operacion es: #{salida}\n"

transport.close()