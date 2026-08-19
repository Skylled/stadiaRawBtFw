// 600deecc  FUN_600deecc  size=72 bytes
// --- callers ---
//   6007ffd0 battery_service__6007ffd0
// --- callees ---
//   6013d0b0 thunk_EXT_FUN_00001ea4


undefined2 FUN_600deecc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 *puVar2;
  undefined2 unaff_r5;
  
  puVar2 = *(undefined4 **)(param_1 + 0xd4);
  if ((*(char *)((int)puVar2 + 0x1a) == '\0') ||
     (cVar1 = thunk_EXT_FUN_00001ea4
                        (*puVar2,*(undefined1 *)(puVar2 + 1),&stack0xfffffff0,1,&stack0xfffffff4,2,
                         200,param_4), cVar1 != '\0')) {
    unaff_r5 = 0xffff;
  }
  return unaff_r5;
}


