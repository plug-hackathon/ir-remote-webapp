class CreateIrSignals < ActiveRecord::Migration
  def change
    create_table :ir_signals do |t|
      t.string :name
      t.string :nec_code

      t.timestamps null: false
    end
  end
end
