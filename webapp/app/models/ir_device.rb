class IrDevice
  NAME = "plughackathon"

  class << self
    def send_nec_code(nec_code)
      Particle.device(NAME).function("sendIRSignal", nec_code)
    end

    def start_emitting_ir_signals
      Particle.device(NAME).function("emitIRSignal", "start")
    end

    def stop_emitting_ir_signals
      Particle.device(NAME).function("emitIRSignal", "stop")
    end
  end
end

