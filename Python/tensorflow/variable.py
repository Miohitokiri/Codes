import tensorflow as tf

B = tf.Variable ( 10 )

with tf.Session() as sess:
    sess.run ( tf.global_variables_initializer() )
    # 用變數要先把變數初始化

    print ( sess.run ( B ) )
    print ( sess.run ( B.assign ( 100 ) ) )
    # 變數可用assign初始化，且一定要開Session run過一次
