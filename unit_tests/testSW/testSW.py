import pymdstresslab

model_name = "SW_StillingerWeber_1985_Si__MO_405512056662_005"

box = pymdstresslab.BoxConfiguration(8000,1)
box.read("config.data",1)

kim = pymdstresslab.Kim(model_name)
