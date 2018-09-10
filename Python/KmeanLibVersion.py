# -*- coding: utf-8 -*-
"""
Created on Thu Sep  6 20:12:30 2018

@author: chen jin

K-mean from sklearn.cluster import KMeans version

Input: 
    example dataset by make_blobs of four clusters
    
Output:
    kmeans: fitted kmean model with cluter = 4
    y_kmeans: kmean prediection
"""
import matplotlib.pyplot as plt
import seaborn as sns; sns.set()  # for plot styling
import numpy as np
from sklearn.datasets.samples_generator import make_blobs
from sklearn.cluster import KMeans

# 1. generate a two-dimensional dataset containing four distinct blobs
X, y_true = make_blobs(n_samples=300, centers=4,
                       cluster_std=0.60, random_state=0)
plt.scatter(X[:, 0], X[:, 1], s=50);

# fit k-mean
kmeans = KMeans(n_clusters=4)
kmeans.fit(X)
y_kmeans = kmeans.predict(X)

# plot results
plt.scatter(X[:, 0], X[:, 1], c=y_kmeans, s=50, cmap='viridis')
centers = kmeans.cluster_centers_
plt.scatter(centers[:, 0], centers[:, 1], c='black', s=200, alpha=0.5);