from Acspy.Clients.SimpleClient import PySimpleClient
 
client = PySimpleClient()
 
hc_cpp = client.getComponent("CPP_DATABASE")
 
print(hc_cpp.getProposalStatus(0))