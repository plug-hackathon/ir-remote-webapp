unless ENV.key?('PARTICLE_ACCESS_TOKEN')
  fail "Please provide a Particle access token:\n\texport PARTICLE_ACCESS_TOKEN=<your_token>"
end

Particle.configure do |c|
  c.access_token = ENV['PARTICLE_ACCESS_TOKEN']
end
