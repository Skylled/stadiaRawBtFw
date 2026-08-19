// 600e1c1c  FUN_600e1c1c  size=44 bytes
// --- callers ---
//   600e1c48 FUN_600e1c48
// --- callees ---
//   600e1a12 FUN_600e1a12


void FUN_600e1c1c(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_38 [10];
  
  puVar4 = local_38;
  puVar2 = param_2;
  do {
    puVar3 = puVar2 + 2;
    uVar1 = puVar2[1];
    *puVar4 = *puVar2;
    puVar4[1] = uVar1;
    puVar4 = puVar4 + 2;
    puVar2 = puVar3;
  } while (puVar3 != param_2 + 10);
  FUN_600e1a12(param_1,local_38);
  return;
}


