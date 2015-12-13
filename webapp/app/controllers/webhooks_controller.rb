class WebhooksController < ApplicationController
  skip_before_action :verify_authenticity_token

  def nec_code
    @ir_signal = IrSignal.incomplete.first
    @ir_signal.update_attribute :nec_code, params[:data].chomp
    IrDevice.stop_emitting_ir_signals
    head :ok
  end
end
