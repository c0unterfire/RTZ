# RTZ
Blackhat Arsernal RTZ

Currently the "Config" settings is stored in HKCU\Software\RTZ

[to add new drives to whitelist]
  set the "enabled" key to 0 - any new drives inserted will be added into the registry as whitelisted
  
[to delete drives from whitelist]
  manually access the registry and delete the subkey from HKCU\Software\RTZ
  
Remember to re-enable the registry key by setting it back to 1 when done

