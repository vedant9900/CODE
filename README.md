# CODE
MY first rep
# 📉 Telco Customer Churn Analysis & Prediction (STAIML Mini Project)

An end-to-end data science project on the IBM Telco Customer Churn dataset — from raw data cleaning to churn prediction with machine learning.

## Problem Statement

Customer churn is one of the biggest challenges telecom companies face. This project analyzes 7,043 real-world customer records to uncover the patterns behind churn — contract type, payment method, monthly charges, tenure, and more — and builds models to predict which customers are likely to leave.

## Dataset

- **Source:** IBM Telco Customer Churn dataset
- **Size:** 7,043 rows × 21 columns
- **Target variable:** `Churn` (Yes/No)
- **Features:** demographics (gender, senior citizen, partner, dependents), account info (tenure, contract, payment method, billing), and service usage (phone, internet, streaming, tech support, etc.)

## Workflow

The notebook follows a full ML pipeline, section by section:

1. **Problem Statement & Dataset Description**
2. **Initial Data Exploration** — shape, dtypes, duplicates, target distribution
3. **Handling Missing Values** — KNN imputation for `TotalCharges`, mode/median/mean imputation comparisons
4. **Data Cleaning** — dropping identifiers, removing duplicates, fixing column formatting and data types
5. **Encoding** — Label Encoding for binary columns, One-Hot Encoding for multi-category columns
6. **Scaling** — Standardization (`StandardScaler`) and Normalization (`MinMaxScaler`)
7. **Outlier Detection** — IQR method, Z-score method, boxplot visualization
8. **Exploratory Data Analysis (EDA)**
   - Univariate: churn distribution, tenure/monthly charges histograms
   - Bivariate: monthly charges vs. churn, tenure vs. monthly charges scatter
   - Multivariate: correlation heatmaps, pairplots, grouped churn breakdowns
9. **Machine Learning Pipeline**
   - Train/test split (80/20)
   - **Linear Regression** (baseline)
   - **Logistic Regression** with `class_weight='balanced'` to handle class imbalance
   - **Random Forest** (tuned: `n_estimators=200`, `max_depth=10`, `min_samples_split=5`)
10. **Model Comparison & Conclusion** — MSE, MAE, and Accuracy compared across all three models with visual bar charts, and a final best-model summary

## Tech Stack

- **Language:** Python 3
- **Core libraries:** `pandas`, `numpy`
- **Visualization:** `matplotlib`, `seaborn`
- **ML / preprocessing:** `scikit-learn` (`KNNImputer`, `SimpleImputer`, `LabelEncoder`, `StandardScaler`, `MinMaxScaler`, `LinearRegression`, `LogisticRegression`, `RandomForestClassifier`, `train_test_split`)
- **Stats:** `scipy.stats`

## Getting Started

### Prerequisites

```bash
pip install pandas numpy matplotlib seaborn scikit-learn scipy jupyter
```

### Run

1. Download the [IBM Telco Customer Churn dataset](https://www.kaggle.com/datasets/blastchar/telco-customer-churn) and place `Telco-Customer-Churn.csv` in the working directory (the notebook currently expects `/content/Telco-Customer-Churn.csv`, which is a Google Colab path — update this to your local path if running outside Colab).
2. Launch Jupyter and open the notebook:

```bash
jupyter notebook FINAL_staiml.ipynb
```

3. Run all cells top to bottom.

## Project Structure

```
FINAL_staiml.ipynb   → Full notebook: EDA, preprocessing, modeling, evaluation
data/                 → (not included) place Telco-Customer-Churn.csv here
```

## Results

The notebook compares Linear Regression, Logistic Regression (balanced), and Random Forest (tuned) using MSE, MAE, and Accuracy, and prints a final summary identifying the best-performing model. See the last section of the notebook for exact numbers on your run.

## Possible Improvements

- Add cross-validation instead of a single train/test split
- Try gradient-boosted models (XGBoost, LightGBM) for comparison
- Add ROC-AUC / precision-recall curves given the class imbalance
- Perform hyperparameter tuning (GridSearchCV / RandomizedSearchCV) on Random Forest
- Add SHAP or feature-importance plots for model interpretability
- Package cleaning/preprocessing steps into a reusable `sklearn` Pipeline

## License

This project is open source and available under the [MIT License](LICENSE).
