import pymdstresslab as pmsl
import numpy as np

model_name = "SW_StillingerWeber_1985_Si__MO_405512056662_005"

body = pmsl.BoxConfiguration(8000,1)
body.read("config.data",1)

kim = pmsl.Kim(model_name)

vec1 = np.array([0., 0., 0.])
vec2 = np.array([60., 60., 60.])

ngrid = 100
randomGrid = pmsl.GridCurrent(vec1, vec2, ngrid)
referenceRandomGrid = pmsl.GridReference(vec1, vec2, ngrid)

ngrid = 20
reference_grid = pmsl.GridReference(vec1, vec2, ngrid)

ngrid = 125
gridFromFile = pmsl.GridCurrent(ngrid)
gridFromFile.read("grid_cauchy.data")

hardy1 = pmsl.Sphere(5.29216036151419)
hardyStress1 = pmsl.StressCauchy("hardy1", hardy1, gridFromFile)

hardy2 = pmsl.Sphere(20.)
hardyStress2 = pmsl.StressCauchy("hardy2", hardy2, gridFromFile)

hardy3 = pmsl.Sphere(5.)
hardyStress3 = pmsl.StressPiola("hardy3",hardy3, reference_grid)

hardy4 = pmsl.Sphere(7.)
hardyStress4 = pmsl.StressPiola("hardy4",hardy4, reference_grid)

hardyRandom = pmsl.Sphere(9.)
hardyStressRandomCauchy = pmsl.StressCauchy("hardyRandomCauchy", hardyRandom, randomGrid)

hardyStressRandomPiola = pmsl.StressPiola("hardyRandomPiola", hardyRandom, referenceRandomGrid)

pmsl.calculateStressCauchy(body, kim, hardyStressRandomCauchy)
