This project uses the DS9 Advertising dataset to predict Sales using regression techniques.  
Linear Regression was selected for the Easy task due to its simplicity, interpretability, and suitability for continuous targets.  
A train–validation split was used to evaluate generalization, and RMSE/R² were chosen as standard regression metrics.  
For the Moderate task, Gradient Descent was implemented from scratch to understand optimization behavior.  
Mini-batch SGD was chosen over batch GD for faster convergence and better computational efficiency.  
Feature standardization was applied to stabilize gradient updates.  
In the Hard task, synthetic noise and outliers were added to test robustness.  
Sklearn Linear Regression showed higher sensitivity to outliers, while Gradient Descent demonstrated more stable coefficients and lower MAE drift.
