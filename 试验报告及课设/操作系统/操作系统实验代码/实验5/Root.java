package 实验5;
import java.util.List;
public interface Root {
    public List<Mode>request(List<Mode> inputlist,List<Mode> freelist,int requestSize);
    public List<Mode>release(List<Mode> inputlist,List<Mode> freelist,int releasesize);
}