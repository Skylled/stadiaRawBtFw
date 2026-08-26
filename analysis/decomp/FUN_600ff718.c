// 600ff718  FUN_600ff718  size=76 bytes
// --- callers ---
//   600c57fc FUN_600c57fc
// --- callees ---
//   600b400c FUN_600b400c


undefined4 FUN_600ff718(undefined1 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 local_14;
  
  local_30 = *param_2;
  uStack_2c = param_2[1];
  uStack_28 = param_2[2];
  uStack_24 = param_2[3];
  local_20 = param_2[4];
  uStack_1c = param_2[5];
  uStack_18 = param_2[6];
  local_14 = *(undefined2 *)(param_2 + 7);
  iVar1 = FUN_600b400c(param_1,&local_30);
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


