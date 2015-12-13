class IrSignalsController < ApplicationController
  def index
    @ir_signals = IrSignal.all
  end

  def new
    @ir_signal = IrSignal.new
  end

  def create
    @ir_signal = IrSignal.new(ir_signal_params)
    if @ir_signal.save
      IrDevice.start_emitting_ir_signals
      redirect_to nec_code_status_ir_signal_url(@ir_signal)
    else
      render :new
    end
  end

  def destroy
    @ir_signal = IrSignal.find(params[:id])
    @ir_signal.destroy
    redirect_to ir_signals_url
  end

  def nec_code_status
    @ir_signal = IrSignal.find(params[:id])
  end

  def nec_code_trigger
    @ir_signal = IrSignal.find(params[:id])
    IrDevice.send_nec_code(@ir_signal.nec_code)
    redirect_to ir_signals_url
  end

  private

  def ir_signal_params
   params.require(:ir_signal).permit(:name)
  end
end
