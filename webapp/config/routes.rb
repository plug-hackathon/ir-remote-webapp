Rails.application.routes.draw do
  root to: "ir_signals#index"
  resources :ir_signals do
    member do
      post :trigger
    end
  end
end
