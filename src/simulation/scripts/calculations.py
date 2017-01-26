import math

EARTH_RADIUS = 6370000.
MAG_LAT=82.7
MAG_LON=-114.4

direction_names = ["N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"]
directions_num = len(direction_names)
directions_step = 360./directions_num

def xyz(lat,lon,r=EARTH_RADIUS):
	x = r*math.cos(math.radians(lat))*math.cos(math.radians(lon))
	y = r*math.cos(math.radians(lat))*math.sin(math.radians(lon))
	z = r*math.sin(math.radians(lat))
	return x,y,z

def dot(p1,p2):
	return p1[0]*p2[0]+p1[1]*p2[1]+p1[2]*p2[2]

def cross(p1,p2):
	x = p1[1]*p2[2]-p1[2]*p2[1]
	y = p1[2]*p2[0]-p1[0]*p2[2]
	z = p1[0]*p2[1]-p1[1]*p2[0]
	return x,y,z

def determinant(p1,p2,p3):
	return dot(p1,cross(p2,p3))

def normalize_angle(angle):
	cycles = angle/360.
	normalized_cycles = cycles - math.floor(cycles)
	return normalized_cycles*360.

def sgn(x):
	if x==0: return 0.
	elif x>0: return 1.
	else: return -1.

def angle(v1,v2,n=None):
	if n==None:
		n=cross(v1,v2)

	prod = dot(v1,v2) / math.sqrt( dot(v1,v1) * dot(v2,v2) )
        if prod>1: prod=1.0 # avoid numerical problems for very small angles
	rad = sgn(determinant(v1,v2,n)) * math.acos( prod )
	deg = math.degrees(rad)
	return normalize_angle(deg)

def great_circle_angle(p1,p2,p3):
	n1=cross(p1,p2)
	n2=cross(p3,p2)
	return angle(n1,n2,p2)
	
def distance(p1,p2,r=EARTH_RADIUS):
	return math.radians(angle(p1,p2)) * r

def direction_name(angle):
	index = int(round( normalize_angle(angle)/directions_step ))
	index %= directions_num
	return direction_names[index]

magnetic_northpole=xyz(MAG_LAT,MAG_LON)
geographic_northpole=xyz(90,0)