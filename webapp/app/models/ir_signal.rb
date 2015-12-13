class IrSignal < ActiveRecord::Base
  scope :incomplete, -> { where(nec_code: nil) }
end
