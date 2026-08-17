// 600a27fc  FUN_600a27fc  size=132 bytes
// --- callers ---
//   600a1fc8 FUN_600a1fc8
//   600a2884 FUN_600a2884
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600b3240 FUN_600b3240


undefined4 FUN_600a27fc(char param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_18 [3];
  undefined1 auStack_15 [5];
  undefined1 *local_10;
  undefined1 local_9;
  
  local_9 = 6;
  local_10 = auStack_18;
  if (param_1 == '\x01') {
    thunk_EXT_FUN_0000b572(auStack_18,param_2,3);
    thunk_EXT_FUN_0000b572(auStack_15,param_2 + 3,3);
    puVar1 = local_10;
  }
  else {
    puVar1 = param_2;
    if (param_1 != '\x02') {
      if (param_1 != '\0') {
        return 5;
      }
      local_9 = 0;
      puVar1 = local_10;
    }
  }
  local_10 = puVar1;
  *(undefined1 *)(DAT_600a2880 + 0x110e) = 1;
  iVar2 = FUN_600b3240(1,param_1,local_10,local_9);
  if (iVar2 == 0) {
    uVar3 = 3;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


