// 600e002e  FUN_600e002e  size=92 bytes
// --- callers ---
//   600843c8 state_machine__600843c8
//   600848bc state_machine__600848bc
// --- callees ---
//   6013d358 thunk_EXT_FUN_0000ab36
//   600dffc0 FUN_600dffc0
//   60084104 state_machine__60084104
//   6013cfe8 thunk_EXT_FUN_0000ab28


void FUN_600e002e(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_28;
  char local_24;
  undefined1 auStack_20 [12];
  
  iVar1 = param_1[0x16];
  *(undefined1 *)(param_1 + 0x16) = 1;
  while( true ) {
    if ((char)param_1[8] == '\0') {
      local_28 = (**(code **)(*param_1 + 0x10))(param_1);
      local_24 = '\x01';
    }
    else {
      thunk_EXT_FUN_0000ab28(auStack_20,param_1 + 7);
      FUN_600dffc0(&local_28,param_1,auStack_20);
    }
    if (local_24 == '\0') break;
    puVar2 = (undefined4 *)thunk_EXT_FUN_0000ab36(&local_28);
    state_machine__60084104(param_1,*puVar2);
  }
  *(char *)(param_1 + 0x16) = (char)iVar1;
  return;
}


