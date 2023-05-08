"""
Collect images from Esp32-cam web server
"""
from everywhereml.data import ImageDataset
from everywhereml.data.collect import MjpegCollector

base_folder = 'boards_over_http'

try:
    # if our dataset folder already exists, load it
    image_dataset = ImageDataset.from_nested_folders(
        name='Boards', 
        base_folder=base_folder
    )
except FileNotFoundError:
    # if the dataset folder does not exists, collect the samples
    # from the Esp32-cam web server
    # duration is how long (in seconds) the program will collect 
    # the images for each class
    mjpeg_collector = MjpegCollector(address='http://192.168.1.93')
    image_dataset = mjpeg_collector.collect_many_classes(
        dataset_name='Boards', 
        base_folder=base_folder,
        duration=40
    )
  
print(image_dataset)