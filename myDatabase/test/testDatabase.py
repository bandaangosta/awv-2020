from Acspy.Clients.SimpleClient import PySimpleClient
import TYPES

client = PySimpleClient()
db = client.getComponent("DATABASE")

t = TYPES.Target(0, TYPES.Position(10,45), 0)
print db.storeProposal([t])
