import tensorflow as tf

A = tf.constant ( 50 )

with tf.Session() as sess:
    B = sess.run ( A )
    print ( B )
