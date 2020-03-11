public class dstack extends stack {
    @Override
    public void push(int data) {
        if (super.getSize() < super.getCapacity() - 1) {
            super.push(data);
        } else {
            int[] oldStack = super.getStack();
            int[] newStack = new int[super.getCapacity() * 2];
            for (int i = 0; i < super.getSize(); i++) {
                newStack[i] = oldStack[i];
            }
            super.setCapacity(super.getCapacity() * 2);
            super.setStack(newStack);
        }
    }
}
