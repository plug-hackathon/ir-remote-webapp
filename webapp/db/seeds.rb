# This file should contain all the record creation needed to seed the database with its default values.
# The data can then be loaded with the rake db:seed (or created alongside the db with db:setup).
#
# Examples:
#
#   cities = City.create([{ name: 'Chicago' }, { name: 'Copenhagen' }])
#   Mayor.create(name: 'Emanuel', city: cities.first)

# Custom Apple TV remote signals (NEC protocol)
IrSignal.create name: "Apple TV (custom) UP",    nec_code: "16736925"
IrSignal.create name: "Apple TV (custom) RIGHT", nec_code: "16761405"
IrSignal.create name: "Apple TV (custom) DOWN",  nec_code: "16754775"
IrSignal.create name: "Apple TV (custom) LEFT",  nec_code: "16720605"
