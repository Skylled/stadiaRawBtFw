// 600df4ec  thunk_FUN_60081500  size=4 bytes
// --- callers ---
// --- callees ---


void thunk_FUN_60081500(int param_1)

{
  char cVar1;
  int iStack_a0;
  undefined4 uStack_9c;
  undefined1 auStack_98 [148];
  
  iStack_a0 = param_1 + 8;
  uStack_9c = *(undefined4 *)(param_1 + 4);
  cVar1 = FUN_600df4c4(DAT_60081544,&iStack_a0);
  if (cVar1 != '\0') {
    iStack_a0 = DAT_60081548;
    uStack_9c = 0xe8;
    FUN_600d3b3a(auStack_98);
    FUN_600d37ac(auStack_98,DAT_6008154c);
    FUN_601016f0(0x28,iStack_a0,uStack_9c,auStack_98);
  }
  return;
}


