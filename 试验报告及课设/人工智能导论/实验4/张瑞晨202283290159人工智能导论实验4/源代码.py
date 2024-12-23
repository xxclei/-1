import matplotlib.cm as cm
import matplotlib.pyplot as plt
import numpy as np
from sklearn.cluster import KMeans
from sklearn.datasets import make_blobs
from sklearn.metrics import silhouette_samples, silhouette_score, adjusted_rand_score, rand_score

# Generating the sample data from make_blobs
X, y_true = make_blobs(
    n_samples=500,
    n_features=2,
    centers=4,
    cluster_std=1,
    center_box=(-10.0, 10.0),
    shuffle=True,
    random_state=1,
)  # For reproducibility

range_n_clusters = [2, 3, 4, 5, 6, 7, 8, 9, 10]

silhouette_avg_list = []
rand_index_list = []
adjusted_rand_index_list = []

# Create a figure for silhouette scores
fig, ax1 = plt.subplots(1, 1, figsize=(10, 6))
ax1.set_title('Silhouette scores for different numbers of clusters')
ax1.set_xlabel('Number of clusters')
ax1.set_ylabel('Silhouette score')

for i, n_clusters in enumerate(range_n_clusters):
    clusterer = KMeans(n_clusters=n_clusters, n_init="auto", random_state=10)
    cluster_labels = clusterer.fit_predict(X)
    
    # Calculate silhouette scores
    silhouette_avg = silhouette_score(X, cluster_labels)
    silhouette_avg_list.append(silhouette_avg)
    
    # Calculate Rand index and adjusted Rand index
    rand_index = rand_score(y_true, cluster_labels)
    adjusted_rand_index = adjusted_rand_score(y_true, cluster_labels)
    rand_index_list.append(rand_index)
    adjusted_rand_index_list.append(adjusted_rand_index)
    
    # Print silhouette scores, Rand index and adjusted Rand index
    print(f"For n_clusters = {n_clusters}, silhouette_avg: {silhouette_avg:.3f}, Rand index: {rand_index:.3f}, Adjusted Rand index: {adjusted_rand_index:.3f}")
    
    # Create a subplot with 1 row and 2 columns for each n_clusters
    fig, (ax2, ax3) = plt.subplots(1, 2, figsize=(18, 7))
    
    # The 1st subplot is the silhouette plot
    ax2.set_xlim([-0.1, 1])
    ax2.set_ylim([0, len(X) + (n_clusters + 1) * 10])
    sample_silhouette_values = silhouette_samples(X, cluster_labels)
    
    y_lower = 10
    for j in range(n_clusters):
        ith_cluster_silhouette_values = sample_silhouette_values[cluster_labels == j]
        ith_cluster_silhouette_values.sort()
        size_cluster_i = ith_cluster_silhouette_values.shape[0]
        y_upper = y_lower + size_cluster_i
        color = cm.nipy_spectral(float(j) / n_clusters)
        ax2.fill_betweenx(np.arange(y_lower, y_upper), 0, ith_cluster_silhouette_values,
                         facecolor=color, edgecolor=color, alpha=0.7)
        ax2.text(-0.05, y_lower + 0.5 * size_cluster_i, str(j))
        y_lower = y_upper + 10  # 10 for the 0 samples
    
    ax2.set_title("The silhouette plot for the various clusters.")
    ax2.set_xlabel("The silhouette coefficient values")
    ax2.set_ylabel("Cluster label")
    ax2.axvline(x=silhouette_avg, color="red", linestyle="--")
    ax2.set_yticks([])  # Clear the yaxis labels / ticks
    ax2.set_xticks([-0.1, 0, 0.2, 0.4, 0.6, 0.8, 1])
    
    # 2nd Plot showing the actual clusters formed
    colors = cm.nipy_spectral(cluster_labels.astype(float) / n_clusters)
    ax3.scatter(X[:, 0], X[:, 1], marker=".", s=30, lw=0, alpha=0.7, c=colors, edgecolor="k")
    centers = clusterer.cluster_centers_
    ax3.scatter(centers[:, 0], centers[:, 1], marker="o", c="white", alpha=1, s=200, edgecolor="k")
    for j, c in enumerate(centers):
        ax3.scatter(c[0], c[1], marker="$%d$" % j, alpha=1, s=50, edgecolor="k")
    ax3.set_title("The visualization of the clustered data.")
    ax3.set_xlabel("Feature space for the 1st feature")
    ax3.set_ylabel("Feature space for the 2nd feature")
    
    plt.suptitle(f"Silhouette analysis for KMeans clustering on sample data with n_clusters = {n_clusters}", fontsize=14, fontweight="bold")
    plt.savefig(f"silhouette_and_clusters_{n_clusters}.jpg")  # Save the figure

# Plot silhouette scores
ax1.plot(range_n_clusters, silhouette_avg_list, marker='o')
ax1.plot(range_n_clusters, rand_index_list, marker='s', color='green')
ax1.plot(range_n_clusters, adjusted_rand_index_list, marker='^', color='blue')
ax1.legend(['Silhouette Score', 'Rand Index', 'Adjusted Rand Index'], loc='best')
plt.savefig("silhouette_scores.jpg")  # Save the silhouette scores plot
plt.show()