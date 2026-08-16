// 60081450  timer__60081450  size=84 bytes
// src: timer.h
// --- callers ---
// --- callees ---
//   600d37ac FUN_600d37ac
//   60101740 FUN_60101740
//   600d3b3a FUN_600d3b3a
//   600cad24 timers__600cad24


/* src: timer.h */

int timer__60081450(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined1 auStack_98 [144];
  
  iVar1 = DAT_600814a4;
  iVar2 = DAT_600814a4 + 0x10;
  *(undefined4 *)(DAT_600814a4 + 8) = param_1;
  *(undefined4 *)(iVar1 + 0xc) = param_2;
  iVar2 = timers__600cad24(DAT_600814ac,6,1,iVar1,DAT_600814a8,iVar2);
  *(int *)(iVar1 + 4) = iVar2;
  if (iVar2 == 0) {
    local_a0 = DAT_600814b0;
    local_9c = 0x4f;
    FUN_600d3b3a(auStack_98);
    FUN_600d37ac(auStack_98,DAT_600814b4);
    FUN_60101740(&local_a0);
  }
  return DAT_600814a4;
}


