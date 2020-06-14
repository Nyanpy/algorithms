# Notebookの表示
from IPython.core.interactiveshell import InteractiveShell
InteractiveShell.ast_node_interactivity = "all"

# 便利なもの
import tqdm
import warnings
warnings.simplefilter('ignore')

# データ操作
import numpy as np
import pandas as pd
pd.set_option('display.max_columns', None)

# データ可視化
import pandas_profiling as pdp
import matplotlib.pyplot as plt
%matplotlib inline
import seaborn as sns
sns.set()

# 前処理
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import MinMaxScaler
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import OneHotEncoder

# 交差検証
from sklearn.model_selection import StratifiedKFold

# 定数の定義
SEED = 2019
N_FOLDS = 10

# モデル作成とGrid search
from sklearn.metrics import mean_squared_error
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split, GridSearchCV

# inputとして与えられたファイル名の一覧を出力
import os
for dirname, _, filenames in os.walk('/kaggle/input'):
    for filename in filenames:
        print(os.path.join(dirname, filename))
