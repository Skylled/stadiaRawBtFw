// 600cca30  FUN_600cca30  size=74 bytes
// --- callers ---
//   6010201a FUN_6010201a
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


uint FUN_600cca30(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined1 local_25 [13];
  undefined4 uStack_18;
  
  puVar1 = local_25 + 1;
  do {
    uVar2 = param_3 / 10;
    puVar1 = puVar1 + -1;
    *puVar1 = *(undefined1 *)(DAT_600cca7c + param_3 % 10);
    param_3 = uVar2;
  } while (uVar2 != 0);
  uVar2 = (int)(local_25 + 1) - (int)puVar1;
  if (param_2 < uVar2) {
    uVar2 = 0xffffffff;
  }
  else {
    uStack_18 = param_4;
    thunk_EXT_FUN_0000b572(param_1,local_25 + (1 - uVar2),uVar2);
  }
  return uVar2;
}


