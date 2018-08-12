#!/usr/bin/env ruby -w

puts "Creating new CLION Arduino project..."
puts "Name?"
name = gets.strip 

puts "Creating directory #{name} ..."
Dir::mkdir(name)

puts "Initializing Arduino Project for CLION ..."
args = %w"pio init --ide clion --board megaatmega2560 -d"
args << name
system(*args)

cpp = "#{name}/src/#{name}.cpp"
code = <<END
#include "Arduino.h"

void setup()
{
    Serial.begin(9600);
}

void loop()
{
}
END
puts "Creating main source code file #{cpp} ..."
File.open(cpp, "w") { |f| f.write(code) }

puts "The #{name} project may now be imported into CLion."
