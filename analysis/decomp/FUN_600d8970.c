// 600d8970  FUN_600d8970  size=36 bytes
// --- callers ---
//   60069c58 adapter__60069c58
//   60069d50 adapter__60069d50
// --- callees ---
//   600d8946 FUN_600d8946
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4 FUN_600d8970(void)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  
  puVar1 = (undefined2 *)FUN_600d8946();
  if (puVar1 == (undefined2 *)0x0) {
    uVar2 = 5;
  }
  else {
    *puVar1 = 0xffff;
    thunk_EXT_FUN_0000b5ba(puVar1 + 2,0,0x15,0xffff,in_r3);
    uVar2 = 0;
  }
  return uVar2;
}


