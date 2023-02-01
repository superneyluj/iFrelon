import os

path_directory = "./boards_over_http/bouchon_vin/"

while True:
   
    if os.path.exists(path_directory):
        for filename in os.listdir(path_directory):
            f = os.path.join(path_directory, filename)
            if os.path.getsize(f) == 0:
                os.remove(f)
