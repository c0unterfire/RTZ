# RTZ
Blackhat Arsernal RTZ

The use of full disk encryption (FDE) has allowed organizations to assume that any data stored on their stolen computers will not be compromised. However, this assumption is being challenged with the development of tools that seek to circumvent FDE protection by extracting cryptographic keys from RAM captures, hibernation files, etc. To address this, RTZ can help protect the assumption that data encrypted by FDE systems will not be compromised. When triggered, RTZ will perform a “self-destruct” of the FDE hard-drive by destroying the encryption key of the FDE system, followed by an automatic shutdown of the system. This process destroys all data on the FDE hard-drive, rendering it permanently inaccessible to all parties. It also flushes volatile memory, hence defeating the current methods used to circumvent FDE protection. 

The "Config" settings are stored in HKCU\Software\RTZ

[to add new drives to whitelist]
  set the "enabled" key to 0 - any new drives inserted will be added into the registry as whitelisted
  
[to delete drives from whitelist]
  manually access the registry and delete the subkey from HKCU\Software\RTZ
  
Remember to re-enable the registry key by setting it back to 1 when done

