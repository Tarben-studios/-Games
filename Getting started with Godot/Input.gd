The `if` function in Godot can be used together with many other built-in Godot functions. Below are the ones I consider most important:

#####################################################
--------------------- Input -------------------------
#####################################################
  if Input.is_anything_pressed()
# o if se torna verdadeiro quando algo é pressionado

  if Input.is_action_pressed("left")
# 1. É preciso passar o parâmetro da função
# 2. A função é verdadeira enquanto o botão estiver sendo pressionado

  if Input.is_action_just_pressed("jump")
# 1. É preciso passar o parâmetro entre aspas
# 2. O if só vai ser verdadeiro no 1º frame que ela for pressionada

  if Input.is_action_just_released("right")
# 1. É preciso passar o parâmetro entre aspas
# 2.  O if só vai ser verdadeiro no 1º frame que ela for solta

  if Input.get_axis("negative", "positive")
# 1. Recebe dois parâmetros, uma para cada direção
# 2. Retorna valores entre -1 para o primeiro e 1 para o segundo, 0 para nenhum

