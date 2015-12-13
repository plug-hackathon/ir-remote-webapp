class IrSignalsController < ApplicationController
  def index
    @ir_signals = IrSignal.all
  end

  def trigger
    @ir_signal = IrSignal.find(params[:id])
    send_nec_code(@ir_signal.nec_code)
    redirect_to ir_signals_url
  end

  private

  def send_nec_code(nec_code)
    Particle.device("plughackathon").function("sendIRSignal", nec_code)
  end
end
