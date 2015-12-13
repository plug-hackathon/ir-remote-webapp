Rails.application.routes.draw do
  root to: "ir_signals#index"

  scope "/webhooks" do
    post "nec_code" => "webhooks#nec_code"
  end

  resources :ir_signals do
    member do
      get  :nec_code_status
      post :nec_code_trigger
    end
  end
end
