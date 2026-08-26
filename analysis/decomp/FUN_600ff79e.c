// 600ff79e  FUN_600ff79e  size=98 bytes
// --- callers ---
//   600c57fc FUN_600c57fc
// --- callees ---
//   600b434c FUN_600b434c


undefined4 FUN_600ff79e(undefined1 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  byte local_3c [4];
  undefined4 auStack_38 [3];
  undefined2 local_2c [12];
  
  pbVar5 = local_3c;
  puVar6 = param_2 + 8;
  do {
    uVar2 = param_2[1];
    uVar3 = param_2[2];
    uVar4 = param_2[3];
    *(undefined4 *)pbVar5 = *param_2;
    *(undefined4 *)(pbVar5 + 4) = uVar2;
    *(undefined4 *)(pbVar5 + 8) = uVar3;
    *(undefined4 *)(pbVar5 + 0xc) = uVar4;
    param_2 = param_2 + 4;
    pbVar5 = pbVar5 + 0x10;
  } while (param_2 != puVar6);
  *(undefined2 *)pbVar5 = *(undefined2 *)param_2;
  if (8 < local_3c[0]) {
    local_3c[0] = 8;
  }
  iVar1 = FUN_600b434c(param_1,local_3c);
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


