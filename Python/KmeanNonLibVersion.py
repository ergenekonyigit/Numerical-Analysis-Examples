# -*- coding: utf-8 -*-
"""
Created on Thu Sep  6 20:19:34 2018

@author: chen jin

k-mean non-lib version:
    Guess some cluster centers
    Repeat until converged
        E-Step: assign points to the nearest cluster center
        M-Step: set the cluster centers to the mean

Input:
    example dataset by make_blobs of four clusters
Output:
    kmeans: fitted kmean model with cluter = 4
    y_kmeans: kmean prediection
"""
import matplotlib.pyplot as plt
import seaborn as sns; sns.set()  # for plot styling
import numpy as np
from sklearn.metrics import pairwise_distances_argmin
from sklearn.datasets.samples_generator import make_blobs

def find_clusters(X, n_clusters, rseed=2):
    # 1. Randomly choose clusters
    rng = np.random.RandomState(rseed)
    i = rng.permutation(X.shape[0])[:n_clusters]
    centers = X[i]
    
    while True:
        # 2a. Assign labels based on closest center
        labels = pairwise_distances_argmin(X, centers)
        
        # 2b. Find new centers from means of points
        new_centers = np.array([X[labels == i].mean(0)
                                for i in range(n_clusters)])
        
        # 2c. Check for convergence
        if np.all(centers == new_centers):
            break
        centers = new_centers
    
    return centers, labels

# 1. generate a two-dimensional dataset containing four distinct blobs
X, y_true = make_blobs(n_samples=300, centers=4,
                       cluster_std=0.60, random_state=0)
# plt.scatter(X[:, 0], X[:, 1], s=50);

centers, labels = find_clusters(X, 4)
plt.scatter(X[:, 0], X[:, 1], c=labels,
            s=50, cmap='viridis');