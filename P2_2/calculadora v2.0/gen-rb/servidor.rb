
require 'thrift'
require './calculadora.rb'

class CalculadoraHandler
    def ping()
        puts "Me han hecho ping"
    end

    def suma(n1, n2)
        puts "Received data: #{n1} #{n2}"
        result = n1 + n2
        puts "Sending data: #{result}"
        result
    end
end

handler = CalculadoraHandler.new
processor = Calculadora::Processor.new(handler)
transport = Thrift::ServerSocket.new('localhost', 9090)
server = Thrift::SimpleServer.new(processor, transport)

begin
    puts "Starting the server..."
    server.serve()
  rescue Thrift::ServerError => e
    puts "Error starting the server: #{e.message}"
end