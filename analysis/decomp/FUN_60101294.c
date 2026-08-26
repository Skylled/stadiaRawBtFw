// 60101294  FUN_60101294  size=110 bytes
// --- callers ---
//   6005be94 FUN_6005be94
// --- callees ---
//   6013cef0 thunk_EXT_FUN_0000887a
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   60100ed8 FUN_60100ed8
//   60100b38 FUN_60100b38


uint FUN_60101294(undefined4 *param_1,undefined1 *param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *local_1c;
  
  if (param_2 == (undefined1 *)0x0) {
    uVar2 = 3;
  }
  else {
    local_1c = param_1 + 1;
    bVar1 = false;
    puVar5 = param_1;
    thunk_EXT_FUN_0000b4c2();
    piVar4 = param_1 + 0x2e;
    for (uVar3 = 0; uVar2 = FUN_60100b38(*param_1), uVar3 < uVar2; uVar3 = uVar3 + 1) {
      if (piVar4[1] + 1 != 0 || *piVar4 != -1) {
        if (bVar1) {
          uVar2 = 0;
          *param_2 = 0;
          goto LAB_601012d8;
        }
        uVar2 = FUN_60100ed8(param_1,uVar3,*piVar4,piVar4[1] + 1,puVar5);
        if ((uVar2 & 0xff) != 0) goto LAB_601012d8;
        bVar1 = true;
      }
      piVar4 = piVar4 + 2;
    }
    uVar2 = 0;
    *param_2 = 1;
LAB_601012d8:
    thunk_EXT_FUN_0000887a(&local_1c);
  }
  return uVar2;
}


