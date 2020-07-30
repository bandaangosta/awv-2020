from Acspy.Clients.SimpleClient import PySimpleClient
 
client = PySimpleClient()
 
# hc_py = client.getComponent("PY_HELLO_COMP")
# hc_java = client.getComponent("JAVA_HELLO_COMP")
hc_cpp = client.getComponent("SCHEDULER")
 
# print(hc_py.printHello())
# print(hc_java.printHello())
print(hc_cpp.printHello())