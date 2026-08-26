// 600ff800  FUN_600ff800  size=98 bytes
// --- callers ---
//   600c57fc FUN_600c57fc
// --- callees ---
//   600b4450 FUN_600b4450


undefined4 FUN_600ff800(undefined1 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_4c;
  undefined4 auStack_48 [3];
  undefined2 local_3c [20];
  
  puVar5 = &local_4c;
  puVar6 = param_2 + 0xc;
  do {
    uVar2 = param_2[1];
    uVar3 = param_2[2];
    uVar4 = param_2[3];
    *puVar5 = *param_2;
    puVar5[1] = uVar2;
    puVar5[2] = uVar3;
    puVar5[3] = uVar4;
    param_2 = param_2 + 4;
    puVar5 = puVar5 + 4;
  } while (param_2 != puVar6);
  *(undefined2 *)puVar5 = *(undefined2 *)param_2;
  if (0x10 < local_4c._1_1_) {
    local_4c._1_1_ = 0x10;
  }
  iVar1 = FUN_600b4450(param_1,&local_4c);
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


