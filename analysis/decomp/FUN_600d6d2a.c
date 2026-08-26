// 600d6d2a  FUN_600d6d2a  size=82 bytes
// --- callers ---
// --- callees ---
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600658b4 haptics_cluster__600658b4
//   6013cef0 thunk_EXT_FUN_0000887a


undefined4 FUN_600d6d2a(char *param_1,undefined2 *param_2,undefined2 *param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (*param_1 == '\0') {
    uVar2 = 9;
  }
  else {
    local_1c = param_1 + 0x14;
    pcVar3 = param_1;
    local_18 = param_3;
    local_14 = param_4;
    thunk_EXT_FUN_0000b4c2();
    if (*(char *)(param_2 + 1) != '\0') {
      local_18 = (undefined2 *)CONCAT22(local_18._2_2_,*param_2);
    }
    local_18._0_3_ = CONCAT12(*(char *)(param_2 + 1) != '\0',(undefined2)local_18);
    bVar1 = *(char *)(param_3 + 1) != '\0';
    if (bVar1) {
      local_14 = CONCAT22(local_14._2_2_,*param_3);
    }
    local_14._0_3_ = CONCAT12(bVar1,(undefined2)local_14);
    uVar2 = haptics_cluster__600658b4(param_1,&local_18,&local_14,bVar1,pcVar3);
    thunk_EXT_FUN_0000887a(&local_1c);
  }
  return uVar2;
}


